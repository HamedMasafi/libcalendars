// Calendars.h

#pragma once
#include "../../src/cl-calendars.h"

using namespace System;

namespace Calendars {

	public ref class Date
	{
	public:
		enum class CalendarType {
			Gregorian = CAL_GREGORIAN,
			Julian = CAL_JULIAN,
			Milankovic = CAL_MILANKOVIC,
			RevisedJulian = CAL_REVISED_JULIAN,
			IslamicCivil = CAL_ISLAMIC_CIVIL,
			Hijri = CAL_HIJRI,
			Jewsish = CAL_JEWSISH,
			Hebrew = CAL_HEBREW,
			SolarHijri = CAL_SOLAR_HIJRI,
			Shamsi = CAL_SHAMSI,
			Persian = CAL_PERSIAN,
		}; 
	private:
		int _year, _month, _day;
		CalendarType _type;

	public:
		property CalendarType Type {
			CalendarType get() {
				return _type;
			}
			void set(CalendarType value) {
				_type = value;
			}
		}
		property int Year {
			int get() {
				return _year;
			}
			void set(int value) {
				_year = value;
			}
		};
		property int Month {
			int get() {
				return _month;
			}
			void set(int value) {
				_month = value;
			}
		};
		property int Day {
			int get() {
				return _day;
			}
			void set(int value) {
				_day = value;
			}
		};

		Date();
		Date(CalendarType type, int julianDay);
		Date(CalendarType type, int year, int month, int day);

		bool IsValid();
		bool IsLeap();
		int ToJulianDay();
		static int DaysInMonth(CalendarType type, int year, int month);
		static int DaysInYear(CalendarType type, int year);
		static int MonthsInYear(CalendarType type, int year);

		Date ^ConvertTo(CalendarType type);
	};
}
