// This is the main DLL file.

#include "stdafx.h"

#include "Calendars.h"

#include "../../src/cl-calendars.h"

inline Calendars::Date::Date() : Date(gcnew System::DateTime)
{
	auto date = gcnew System::DateTime;
	_type = CalendarType::Gregorian;
	_year = date->Year;
	_month = date->Month;
	_day = date->Day;
}

Calendars::Date::Date(System::DateTime ^date)
{
	_type = CalendarType::Gregorian;
	_year = date->Year;
	_month = date->Month;
	_day = date->Day;
}

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
	return is_valid(uint8_t(_type), _year, _month, _day) != 0;
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

System::DateTime Calendars::Date::ToDate()
{
	if (_type != CalendarType::Gregorian) {
		auto b = ConvertTo(CalendarType::Gregorian);
		return *gcnew System::DateTime(b->Year, b->Month, b->Day);
	}

	return *gcnew System::DateTime(_year, _month, _day);
}

Calendars::Date ^Calendars::Date::ConvertTo(CalendarType type)
{
	int16_t y;
	uint8_t m;
	uint16_t d;
	convert_date(uint8_t(_type), uint8_t(type),
		int16_t(_year), uint8_t(_month), uint16_t(_day),
		&y, &m, &d);

	return gcnew Date(type, y, m, d);
}

bool Calendars::Date::operator==(Calendars::Date ^l, Calendars::Date ^r)
{
	return l->ToJulianDay() == r->ToJulianDay();
}
