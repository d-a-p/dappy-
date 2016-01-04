#pragma once
#include<Windows.h>

namespace dappy {

	class Timer {
	private:
		LARGE_INTEGER m_Start;
		double m_Freq;
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Freq = 1.0/frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}
		void reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		float elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			//m_Start = current;
			unsigned __int64 cycle = current.QuadPart - m_Start.QuadPart;
			return (float)(cycle* m_Freq);
		}

	};

}