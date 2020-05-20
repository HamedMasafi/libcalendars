using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Calendars;

namespace UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void DoubleConvert()
        {
            var d1 = new Date(Date.CalendarType.Persian, 1397, 1, 1);
            var d2 = d1.ConvertTo(Date.CalendarType.Gregorian)
                .ConvertTo(Date.CalendarType.Persian);
            Assert.IsTrue(d1.IsValid());
            Assert.AreEqual(d1.Year, d2.Year);
            Assert.AreEqual(d1.Month, d2.Month);
            Assert.AreEqual(d1.Day, d2.Day);
            Assert.AreEqual(d1.ToJulianDay(), d2.ToJulianDay());
            Assert.IsTrue(d1 == d2);
        }

        [TestMethod]
        public void DateTime()
        {
            var dateTime = new DateTime();
            var d2 = new Calendars.Date(dateTime);
            var dateTime2 = d2.ToDate();

            Assert.AreEqual(dateTime, dateTime2);
        }

        [TestMethod]
        public void Ctor()
        {
            var date = new System.DateTime();
            var d = new Calendars.Date();
            Assert.AreEqual(date.Date, d.ToDate().Date);
        }
    }
}
