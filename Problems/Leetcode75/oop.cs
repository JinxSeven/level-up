using System;

public class Solution
{
    public class Car
    {
        public string Make { get; private set; }
        public string Model { get; private set; }

        private int year;

        public int Year
        {
            get { return year; }
            set
            {
                if (value <= 2000)
                    throw new ArgumentException("Year must be greater than 2000");
                year = value;
            }
        }

        public Car(string make, string model, int year)
        {
            Make = make;
            Model = model;
            Year = year;
        }

        public virtual string StartEngine()
        {
            return "Fuel Engine Started";
        }
    }

    public class ElectricCar : Car
    {
        public int BatteryRange { get; set; }

        public ElectricCar(string make, string model, int year, int batteryRange)
            : base(make, model, year)
        {
            BatteryRange = batteryRange;
        }

        public override string StartEngine()
        {
            return "Electric motor activated";
        }
    }

    public static void Main()
    {
        var newCar = new ElectricCar("Tesla", "Model X", 2018, 100);

        Console.WriteLine(newCar.StartEngine());
    }
}
