using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Xml;

namespace Bai05
{
    public class Program
    {
        static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Company company = new ();
            
            //Ý 2
            company.Input();
            Console.WriteLine("\n--------------Print With No Condition--------------");
            company.Output();
            
            //Ý 3
            Console.WriteLine("\n--------------Print With Condition--------------");
            Console.WriteLine("\n--------------Land has area > 100m2--------------");
            company.PrintWithCondition(typeCondition:"Land",areaCondition:">100");
            Console.WriteLine("\n--------------TownHouse has area > 60m2 and year of construction >= 2019 --------------");
            company.PrintWithCondition(typeCondition:"TownHouse", areaCondition:">60", yearBuiltCondition:">=2019");

            //Ý 4
            Console.WriteLine("Input your position you want to find: ");
            string? positionFound = Console.ReadLine();
            Console.WriteLine("Input your price you want to find: ");
            string? priceFound = Console.ReadLine();
            Console.WriteLine("Input your area you want to find: ");
            string? areaFound = Console.ReadLine();
            Console.WriteLine("\n---Townhouse has found---");
            company.PrintWithCondition(typeCondition: "TownHouse",
                                       positionCondition: positionFound,
                                       priceCondition: "<=" + priceFound,
                                       areaCondition: ">=" + areaFound);
            Console.WriteLine("\n---Apartment has found---");
            company.PrintWithCondition(typeCondition: "Apartment",
                                       positionCondition: positionFound,
                                       priceCondition: "<=" + priceFound,
                                       areaCondition: ">=" + areaFound);
        }
    }

    public class Company
    {
        List<RealEstate>? _realEstates;
       
        public Company()
        {
            _realEstates = new List<RealEstate>();
        }

        ~Company()
        {
            _realEstates = null;
        }

        public void Input()
        {
            ConsoleKey? keyPressed = null;
            while (keyPressed != ConsoleKey.N && keyPressed != ConsoleKey.Escape)
            {
                int? type;
                do
                {
                    Console.Write("Input the type of real estate you want(1: Land, 2: TownHouse 3: Apartment): ");
                    type = int.Parse(s: Console.ReadLine());
                }
                while (type < 1 || type > 3);
                if (_realEstates != null)
                {
                    switch (type)
                    {
                        case 1:
                            Land land = new();
                            _realEstates.Add(land);
                            break;
                        case 2:
                            TownHouse townHouse = new();
                            _realEstates.Add(townHouse);
                            break;
                        case 3:
                            Apartment apartment = new();
                            _realEstates.Add(apartment);
                            break;
                        default:
                            break;
                    }
                    _realEstates.Last().Input();
                }
                Console.WriteLine();
                Console.WriteLine("Do you want to continue?(Y/N)");
                keyPressed = Console.ReadKey(true).Key;
            }
        }
        
        public void Output()
        {
            int i = 1;
            _realEstates?.ForEach(realEstate =>
            {
                Console.WriteLine($"-----------Real Estate {i++} -------------");
                realEstate.Output();
            });
        }

        public void PrintWithCondition(string? typeCondition = null, 
                                       string? positionCondition = null, 
                                       string? priceCondition = null,
                                       string? areaCondition = null, 
                                       string? yearBuiltCondition = null)
        {
            List<RealEstate>? realEstatesWithCondition = _realEstates;
            if (typeCondition != null)
            {
                realEstatesWithCondition = realEstatesWithCondition
                    ?.Where(realEstate => realEstate.CheckType(typeCondition)).ToList();
            }

            if(positionCondition != null)
            {
                realEstatesWithCondition = realEstatesWithCondition
                   ?.Where(realEstate => realEstate.CheckPosition(positionCondition)).ToList();
            }

            if(priceCondition != null)
            {
                realEstatesWithCondition = realEstatesWithCondition
                  ?.Where(realEstate => realEstate.CheckPriceWithCondition(priceCondition)).ToList();
            }

            if (areaCondition != null)
            {
                realEstatesWithCondition = realEstatesWithCondition
                  ?.Where(realEstate => realEstate.CheckAreaWithCondition(areaCondition)).ToList();
            }

            if (yearBuiltCondition != null)
            {
                realEstatesWithCondition = realEstatesWithCondition
                  ?.Where(realEstate => realEstate is TownHouse 
                                        &&(realEstate as TownHouse).CheckYearBuiltWithCondition(yearBuiltCondition)).ToList();
            }

            
            realEstatesWithCondition?.ForEach(realEstate => realEstate.Output());
            if (realEstatesWithCondition?.Count == 0)
                Console.WriteLine("Can not find any valid member");
            
        }

        public List<RealEstate>? FilterByType(string type)
            => _realEstates?.Where(realEstate => realEstate.CheckType(type)).ToList();
       
        public List<RealEstate>? FilterByAreaCondition(string areaCondition)
            => _realEstates?.Where(realEstate => realEstate.CheckAreaWithCondition(areaCondition)).ToList();

        public List<RealEstate>? FilterByYearBuiltCondition(string yearBuiltCondition)
            => _realEstates?.Where(realEstate
                                    => realEstate is TownHouse
                                       && (realEstate as TownHouse).CheckYearBuiltWithCondition(yearBuiltCondition))
                            .ToList();
    }


    public abstract class RealEstate
    {
        protected string? _position;
        protected double? _price;
        protected double? _area;
      
        public string? Positon
        {
            get => _position;
        }
        public double? Price
        {
            get => _price;
        }
        
        public double? Area
        {
            get => _area;
        }
    
        public RealEstate()
        {
            _position = null;
            _price = null;
            _area = null;
        }

        public RealEstate(string? position, double? price, double? area)
        {
            _position = position;
            _price = price;
            _area = area;
        }

        public virtual void Input()
        {
            Console.Write("Input position: ");
            _position = Console.ReadLine();
            Console.Write("Input price: ");
            _price = double.Parse(Console.ReadLine());
            Console.Write("Input area: ");
            _area = double.Parse(Console.ReadLine());
        }

        public virtual void Output()
        {
            
            Console.WriteLine($"---{this.GetType().Name}---");
            Console.WriteLine("Position: " + _position);
            Console.WriteLine("Price: " + _price);
            Console.WriteLine("Area: " + _area);
        }

        public bool CheckType(string type)
            => this.GetType().Name == type;

        public bool CheckPosition(string position) 
            => _position?.ToUpper() == position.ToUpper();

        public bool CheckAreaWithCondition(string areaCondition)
        {
            try
            {
                if (areaCondition.StartsWith(">="))
                {
                    return _area >= double.Parse(areaCondition[2..]);
                }
                else if (areaCondition.StartsWith("<="))
                {
                    return _area <= double.Parse(areaCondition[2..]);
                }
                else if (areaCondition.StartsWith('>'))
                {
                    return _area > double.Parse(areaCondition[1..]);
                }
                else if (areaCondition.StartsWith('<'))
                {
                    return _area < double.Parse(areaCondition[1..]);
                }
                else if (areaCondition.StartsWith('='))
                {
                    return _area == double.Parse(areaCondition[1..]);
                }
                else if (areaCondition.StartsWith('!'))
                {
                    return _area != double.Parse(areaCondition[1..]);
                }
                else
                {
                    return _area == double.Parse(areaCondition);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }
        }

        public bool CheckPriceWithCondition(string priceCondition)
        {
            try
            {
                if (priceCondition.StartsWith(">="))
                {
                    return _price >= double.Parse(priceCondition[2..]);
                }
                else if (priceCondition.StartsWith("<="))
                {
                    return _price <= double.Parse(priceCondition[2..]);
                }
                else if (priceCondition.StartsWith('>'))
                {
                    return _price > double.Parse(priceCondition[1..]);
                }
                else if (priceCondition.StartsWith('<'))
                {
                    return _price < double.Parse(priceCondition[1..]);
                }
                else if (priceCondition.StartsWith('='))
                {
                    return _price == double.Parse(priceCondition[1..]);
                }
                else if (priceCondition.StartsWith('!'))
                {
                    return _price != double.Parse(priceCondition[1..]);
                }
                else
                {
                    return _price == double.Parse(priceCondition);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }
        }
    }

    public class Land : RealEstate
    {
        public Land() : base() { }

        public Land(string? position, double? price, double? area)
            : base(position, price, area) { }

        public override void Input()
        {
            base.Input();
        }

        public override void Output()
        {
            base.Output();
        }

    }

    public class TownHouse : RealEstate
    {

        private int? _yearBuilt;
        private int? _floorNumber;

        public int? YearBuilt
        {
            get => _yearBuilt;
        }

        public int? FloorNumber
        {
            get => _floorNumber;
        }

        public TownHouse() : base()
        {
            _yearBuilt = null;
            _floorNumber = null;
            
        }

        public TownHouse(string? position, double? price, double? area, int? yearBuilt, int? floorNumber)
            : base(position, price, area)
        {
            _yearBuilt = yearBuilt;
            _floorNumber = floorNumber;
        }
        
        public override void Input()
        {
            base.Input();
            Console.Write("Input year of construction: ");
            _yearBuilt = int.Parse(Console.ReadLine());
            Console.Write("Input number of floor: ");
            _floorNumber = int.Parse(Console.ReadLine());
        }

        public override void Output()
        {
            base.Output();
            Console.WriteLine("The year of construction is: " + _yearBuilt);
            Console.WriteLine("The number of floor is: " + _floorNumber);
        }

        public bool CheckYearBuiltWithCondition(string yearBuiltCondition)
        {
            try
            {
                if (yearBuiltCondition.StartsWith(">="))
                {
                    return _yearBuilt >= double.Parse(yearBuiltCondition[2..]);
                }
                else if (yearBuiltCondition.StartsWith("<="))
                {
                    return _yearBuilt <= double.Parse(yearBuiltCondition[2..]);
                }
                else if (yearBuiltCondition.StartsWith('>'))
                {
                    return _yearBuilt > int.Parse(yearBuiltCondition[1..]);
                }
                else if (yearBuiltCondition.StartsWith('<'))
                {
                    return _yearBuilt < int.Parse(yearBuiltCondition[1..]);
                }
                else if (yearBuiltCondition.StartsWith('='))
                {
                    return _yearBuilt == int.Parse(yearBuiltCondition[1..]);
                }
                else if (yearBuiltCondition.StartsWith('!'))
                {
                    return _yearBuilt != int.Parse(yearBuiltCondition[1..]);
                }
                else
                {
                    return _yearBuilt == int.Parse(yearBuiltCondition);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }
        }
    }

    public class Apartment : RealEstate
    {
        private int? _floorNumber;

        public int? FloorNumber
        {
            get => _floorNumber;
        }
        
        public Apartment() : base()
        {
            _floorNumber = null;
        }

        public Apartment(string? position, double? price, double? area, int? floorNumber)
            : base(position, price, area)
        {
            _floorNumber = floorNumber;
        }

        public override void Input()
        {
            base.Input();
            Console.Write("Input number of floor: ");
            _floorNumber = int.Parse(Console.ReadLine());
        }

        public override void Output()
        {
            base.Output();
            Console.WriteLine("The number of floor is: " + _floorNumber);
        }
        
    }
}