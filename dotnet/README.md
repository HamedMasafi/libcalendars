# LibCalendars.net

## Installtion
Add a reference to Calendars.dll in your project and done!

## Usage

### Sample usage
```csharp
var date = new Calendars.Date(Calendars.Date.CalendarType.Persian);
Console.WriteLine("{0},-{1}-{2}", date.Year, date.Month, date.Day);
```

### Converting dates
```csharp
var date = new Calendars.Date();
var date2 = date.ConvertTo(Calendars.Date.CalendarType.IslamicCivil);
Console.WriteLine("Today in islamic civil calendar is: {0},-{1}-{2}", date.Year, date.Month, date.Day);
````

### Create from calendar type
```csharp
var date = new Calendars.Date(Calendars.Date.CalendarType.Persian, 1399, 2, 30);
System.DateTime dt = date.ToDate();
```

## Api Reference

### Constructors
```csharp
Date();
Date(System::DateTime date);
Date(CalendarType type, System::DateTime date);
Date(CalendarType type, int julianDay);
Date(CalendarType type, int year, int month, int day);
```

### Member functions
**bool IsValid()**

Checks if a givend date is valid is specified calendar or not (exists, or fits in calendar rules).

**bool IsLeap()**

Decide wheter a given year number in a specified calendar is a leap year (have some extra number of month or days) or not.

**Date ConvertTo(CalendarType type)**

Convert current Date object into new object by given year for specified calendar type.


### Static methods
**int DaysInMonth(CalendarType type, int year, int month)**

Returns number of days in a given year for specified calendar type.

**int DaysInYear(CalendarType type, int year)**

Returns number of days of a specific month in a given year for specified calendar type.

**int MonthsInYear(CalendarType type, int year)**

Returns number of month in a given year for specified calendar type.

