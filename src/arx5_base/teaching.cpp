#include "arx5_base/teaching.h"
#include <iostream>

Recorder::Recorder(std::string file_name, float frequency)
{
  saved_file_name = file_name;
  recording_data.append(std::to_string(frequency));
  recording_data.append("\n");
};

void Recorder::updateRecording(std::vector<double> data)
{
  for (int i = 0; i < 6; i++)
  {
      recording_data.append(std::to_string(data[i]));
      recording_data.append(" ");
  }
  recording_data.append("\n");
};

void Recorder::endRecording()
{
  std::string saving_path;
  saving_path = "/home/hanzx/Dev/Projects/libarx5/saved_data";
  saving_path.append("/");
  saving_path.append(saved_file_name);
  saving_path.append(".txt");

  std::ofstream out(saving_path);
  if (out.is_open())
  {
    out << recording_data;
    std::cout <<saved_file_name<<" saved!"<< std::endl;
    out.close();
    recording_data.clear();
  }
};

Player::Player(std::string file_name)
{
  std::string data_path;
  data_path = "/home/hanzx/Dev/Projects/libarx5/saved_data";
  data_path.append("/");
  data_path.append(file_name);
  data_path.append(".txt");
  record_stream.open(data_path, std::ios::in);
  record_stream >> frequency;
};

float Player::getFrequency()
{
  return frequency;
}

std::vector<double> Player::getData()
{
  for(int i=0; i<6; i++)
  {
    record_stream >> top_data[i];
    // std::cout<<data[i]<<" ";
  }
  // std::cout<<std::endl;

  return top_data;
};

bool Player::isEnd()
{
  if (record_stream.eof())
  {
    record_stream.close();
    return true;
  }
  else
  {
    return false;
  }
};