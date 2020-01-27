#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  std::map<std::string, long> cpuStats = LinuxParser::CpuUtilization();
  long idle = cpuStats["idle"] + cpuStats["iowait"];
  long nonIdle = cpuStats["user"] + cpuStats["nice"] + cpuStats["system"] +
                 cpuStats["irq"] + cpuStats["softirq"] + cpuStats["steal"];
  float total = idle + nonIdle;
  float diff = total - idle;
  return diff / total;
}