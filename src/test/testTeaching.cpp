#include <arx5_base/teaching.h>
#include <arx5_utils/rate.h>
#include <iostream>

int main()
{
  int freq = 100;
  std::string file_name = "test";
  Recorder recorder(file_name, freq);
  Rate rate(freq);
  std::vector<double> data = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  for(int i=0; i<100; i++)
  {
    recorder.updateRecording(data);
    for(int i=0; i<6; i++)
    {
      data[i] += 1.0;
    }
    rate.sleep();
  }

  recorder.endRecording();

  Player player(file_name);
  float freq2 = player.getFrequency();
  std::cout<<"data frequency: "<<freq2<<std::endl;
  std::vector<double> data2 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  Rate rate2(freq2);
  while(!player.isEnd())
  {
    data2 = player.getData();
    for(int i = 0; i < 6; i++)
    {
      std::cout<<data2[i]<<" ";
    }
    std::cout<<std::endl;
    rate2.sleep();
  }

  std::cout<<"playing ended!"<<std::endl;

  return 0;
}