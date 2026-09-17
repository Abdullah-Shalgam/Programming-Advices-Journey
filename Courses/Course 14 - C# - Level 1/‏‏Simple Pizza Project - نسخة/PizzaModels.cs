using System;
using System.Collections.Generic;

namespace Simple_Pizza_Project
{
    public enum PizzaSize
    {
        Small = 20,
        Medium = 30,
        Large = 40
    }

    public enum CrustType
    {
        Thin = 0,
        Thick = 10
    }

    public enum DiningOption
    {
        EatIn,
        TakeOut
    }

    [Flags]
    public enum Toppings
    {
        None = 0,
        ExtraCheese = 1,
        Mushrooms = 2,
        Tomatoes = 4,
        Onion = 8,
        Olives = 16,
        GreenPeppers = 32
    }

    public class PizzaOrder
    {
        public PizzaSize Size { get; set; } = PizzaSize.Medium;
        public CrustType Crust { get; set; } = CrustType.Thin;
        public DiningOption Dining { get; set; } = DiningOption.EatIn;
        public Toppings SelectedToppings { get; set; } = Toppings.None;

        public decimal CalculateTotal()
        {
            decimal total = (decimal)Size + (decimal)Crust;

            if ((SelectedToppings & Toppings.ExtraCheese) != 0) total += 5;
            if ((SelectedToppings & Toppings.Mushrooms) != 0) total += 3;
            if ((SelectedToppings & Toppings.Tomatoes) != 0) total += 3;
            if ((SelectedToppings & Toppings.Onion) != 0) total += 7;
            if ((SelectedToppings & Toppings.Olives) != 0) total += 4;
            if ((SelectedToppings & Toppings.GreenPeppers) != 0) total += 6;

            return total;
        }

        public List<string> GetToppingNames()
        {
            var list = new List<string>();
            if ((SelectedToppings & Toppings.ExtraCheese) != 0) list.Add("🧀 Extra Cheese");
            if ((SelectedToppings & Toppings.Mushrooms) != 0) list.Add("🍄 Mushrooms");
            if ((SelectedToppings & Toppings.Tomatoes) != 0) list.Add("🍅 Tomatoes");
            if ((SelectedToppings & Toppings.Onion) != 0) list.Add("🧅 Onion");
            if ((SelectedToppings & Toppings.Olives) != 0) list.Add("🫒 Olives");
            if ((SelectedToppings & Toppings.GreenPeppers) != 0) list.Add("🫑 Green Peppers");
            return list;
        }
    }
}