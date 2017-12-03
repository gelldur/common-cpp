//
// Created by Dawid Drozd aka Gelldur on 31.10.17.
//
#include "Time.h"
//////////////////////////////////

namespace Acme
{

namespace Time
{

std::chrono::seconds getUnixTimeStamp()
{
	const auto now = std::chrono::system_clock::now();
	const auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::seconds>(duration);
}

}

}