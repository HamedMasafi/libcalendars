using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Calendars;

namespace UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            var a = new Calendars.Date();
            var b = a.IsValid();
        }
    }
}
