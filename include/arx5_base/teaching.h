#ifndef TEACHING_H
#define TEACHING_H

#include <vector>
#include <string>
#include <fstream>

class Recorder
{
  public:
    Recorder(std::string file_name, float frequency);
    ~Recorder() = default;

    void updateRecording(std::vector<double> data);
    void endRecording();

  private:
    std::string saved_file_name;
    std::string recording_data;
};

class Player
{
  public:
    Player(std::string file_name);
    ~Player() = default;

    float getFrequency();
    std::vector<double> getData();
    bool isEnd();

  private:
    std::ifstream record_stream;
    std::string data;
    float frequency;
    int dataIndex = 0;
    std::vector<double> top_data = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
};

#endif