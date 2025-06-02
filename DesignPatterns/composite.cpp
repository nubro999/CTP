#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


class MediaClip {
    private :
        string name;
    public :
        MediaClip(const string& name) : name(name) {}
        virtual ~MediaClip() {}

        virtual void play() const {
            cout << "Playing clip: " << name << endl;
        }

        virtual void add(MediaClip* clip) {
            cout << "Cannot add to a single clip." << endl;
        }

        virtual void remove(MediaClip* clip) {
            cout << "Cannot remove from a single clip." << endl;
        }
        virtual void getChild(int index) {
            cout << "Cannot get child from a single clip." << endl;
        }
        string getName() const {
            return name;
        }
};

class VideoClip : public MediaClip {
    private :
        string name;
    public :
        VideoClip(const string& name) : MediaClip(name) {}

        void play() const override {
            cout << "Playing video clip: " << getName() << endl;
        }
};

class AudioClip : public MediaClip {
    private :
        string name;
    public :
        AudioClip(const string& name) : MediaClip(name) {}

        void play() const override {
            cout << "Playing audio clip: " << getName() << endl;
        }
};

class AddSequence : public MediaClip {
    private :
        vector<MediaClip*> clips;
        string name;
    public :
        AddSequence(const string& name) : MediaClip(name) {}

        void play() const override {
            cout << "Playing sequence: " << getName() << endl;
            for (const auto& clip : clips) {
                clip->play();
            }
        }

        void add(MediaClip* clip) override {
            clips.push_back(clip);
        }

        void remove(MediaClip* clip) override {
            for (auto it = clips.begin(); it != clips.end(); ++it) {
                if (*it == clip) {
                    clips.erase(it);
                    cout << "Removed clip: " << clip->getName() << endl;
                    return;
                }
            }
        }

        void getChild(int index) override {
            if (index < 0 || index >= clips.size()) {
                cout << "Index out of bounds." << endl;
                return;
            }
            clips[index]->play();
        }
};

int main() {
    MediaClip* video1 = new VideoClip("Video 1");
    MediaClip* audio1 = new AudioClip("Audio 1");
    MediaClip* audio2 = new AudioClip("Audio 2");

    AddSequence* sequence = new AddSequence("My Sequence");
    sequence->add(video1);
    sequence->add(audio1);
    sequence->add(audio2);

    sequence->play(); // Play the entire sequence

    sequence->remove(audio1); // Remove audio1 from the sequence
    sequence->getChild(0); // Play the first clip in the sequence
    sequence->getChild(1); // Play the second clip in the sequence

    delete video1;
    delete audio1;
    delete audio2;
    delete sequence;

    getchar(); // Wait for user input before closing the console window
    return 0;
}