// This is the main DLL file.

#include "stdafx.h"

#include "Calendars.h"

#include "../../src/cl-calendars.h"

inline Calendars::Date::Date() 
	: _year(0), _month(0), _day(0)
{}

Calendars::Date::Date(CalendarType type, int julianDay)
{
	int16_t y;
	uint8_t m;
	uint16_t d;
	to_date(uint8_t(type), julianDay, &y, &m, &d);
	_year = y;
	_month = m;
	_day = d;
}

inline Calendars::Date::Date(Calendars::Date::CalendarType type, int year, int month, int day) 
	: _type(type), _year(year), _month(month), _day(day)
{}

inline bool Calendars::Date::IsValid() {
	return is_valid(uint8_t(_type), _year, _month, _day);
}

bool Calendars::Date::IsLeap()
{
	return is_leap(uint8_t(_type), _year);
}

int Calendars::Date::ToJulianDay()
{
	uint32_t jdn;
	to_jdn(uint8_t(_type), &jdn, _year, _month, _day);
	return jdn;
}

int Calendars::Date::DaysInMonth(CalendarType type, int year, int month)
{
	return days_in_month(uint8_t(year), month, year);
}

int Calendars::Date::DaysInYear(CalendarType type, int year)
{
	return days_in_year(uint8_t(type), year);
}

int Calendars::Date::MonthsInYear(CalendarType type, int year)
{
	return month_in_year(uint8_t(type), year);
}

Calendars::Date ^Calendars::Date::ConvertTo(CalendarType type)
{
	int16_t y;
	uint8_t m;
	uint16_t d;
	convert_date(uint8_t(_type), _year, _month, _day, 
		uint8_t(type), &y, &m, &d);

	return gcnew Date(type, y, m, d);
}
