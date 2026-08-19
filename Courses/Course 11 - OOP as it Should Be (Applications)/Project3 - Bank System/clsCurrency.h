#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Global.h"
#include "MyStringLib.h"

/**
 * @class clsCurrency
 * @brief Domain Model for managing foreign exchange rates and conversions.
 */
class clsCurrency
{
private:
    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };
    enMode _Mode;

    std::string _Country;
    std::string _CurrencyCode;
    std::string _CurrencyName;
    double _Rate;

    inline static std::string _SystemCurrencyCode = "USD";

    static clsCurrency _ConvertLinetoCurrencyObject(const std::string &Line, const std::string &Separator = "#//#")
    {
        std::vector<std::string> vCurrencyData = MyStringLib::SplitString(Line, Separator);
        if (vCurrencyData.size() < 4)
            return GetEmptyCurrencyObject();

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], std::stod(vCurrencyData[3]));
    }

    static std::string _ConvertCurrencyObjectToLine(const clsCurrency &Currency, const std::string &Separator = "#//#")
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(4) << Currency.GetRate();

        return Currency.GetCountry() + Separator +
               Currency.GetCurrencyCode() + Separator +
               Currency.GetCurrencyName() + Separator +
               ss.str();
    }

    static std::vector<clsCurrency> _LoadCurrenciesDataFromFile()
    {
        std::vector<clsCurrency> vCurrencies;
        std::fstream MyFile(Global::CurrenciesFilePath, std::ios::in);

        if (MyFile.is_open())
        {
            std::string Line;
            while (std::getline(MyFile, Line))
            {
                if (!Line.empty())
                {
                    vCurrencies.push_back(_ConvertLinetoCurrencyObject(Line));
                }
            }
            MyFile.close();
        }
        return vCurrencies;
    }

    static void _SaveCurrencyDataToFile(const std::vector<clsCurrency> &vCurrencies)
    {
        std::fstream MyFile(Global::CurrenciesFilePath, std::ios::out);

        if (MyFile.is_open())
        {
            for (const clsCurrency &C : vCurrencies)
            {
                MyFile << _ConvertCurrencyObjectToLine(C) << "\n";
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        std::vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency &C : vCurrencies)
        {
            if (C.GetCurrencyCode() == GetCurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(vCurrencies);
    }

public:
    clsCurrency(enMode Mode, const std::string &Country, const std::string &CurrencyCode, const std::string &CurrencyName, double Rate)
        : _Mode(Mode), _Country(Country), _CurrencyCode(CurrencyCode), _CurrencyName(CurrencyName), _Rate(Rate)
    {
    }

    static clsCurrency GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

    bool IsEmpty() const { return (_Mode == enMode::EmptyMode); }

    std::string GetCountry() const { return _Country; }
    std::string GetCurrencyCode() const { return _CurrencyCode; }
    std::string GetCurrencyName() const { return _CurrencyName; }
    double GetRate() const { return _Rate; }

    void UpdateRate(double NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    double ConvertToUSD(double Amount) const
    {
        if (_Rate == 0)
            return 0;
        return Amount / _Rate;
    }

    double ConvertToOtherCurrency(double Amount, const clsCurrency &Currency2) const
    {
        double AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.GetCurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return AmountInUSD * Currency2.GetRate();
    }

    static clsCurrency GetSystemCurrency()
    {
        clsCurrency Currency = FindByCode(_SystemCurrencyCode);
        if (Currency.IsEmpty())
        {
            _SystemCurrencyCode = "USD";
            return FindByCode("USD");
        }
        return Currency;
    }

    static void SetSystemCurrency(const clsCurrency &Currency)
    {
        if (!Currency.IsEmpty())
        {
            _SystemCurrencyCode = Currency.GetCurrencyCode();
        }
    }

    static double ConvertFromBaseUSD(double AmountInUSD)
    {
        clsCurrency SysCurrency = GetSystemCurrency();
        return AmountInUSD * SysCurrency.GetRate();
    }

    static double ConvertToBaseUSD(double AmountInSystemCurrency)
    {
        clsCurrency SysCurrency = GetSystemCurrency();
        if (SysCurrency.GetRate() == 0)
            return 0;
        return AmountInSystemCurrency / SysCurrency.GetRate();
    }

    static std::string FormatSystemAmount(double AmountInUSD)
    {
        clsCurrency SysCurrency = GetSystemCurrency();
        double ConvertedAmount = ConvertFromBaseUSD(AmountInUSD);

        std::ostringstream ss;
        ss << "$ " << std::fixed << std::setprecision(2) << ConvertedAmount << " " << SysCurrency.GetCurrencyCode();
        return ss.str();
    }

    static clsCurrency FindByCode(std::string CurrencyCode)
    {
        CurrencyCode = MyStringLib::CapitalizeAllString(CurrencyCode);
        std::vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

        for (const clsCurrency &C : vCurrencies)
        {
            if (C.GetCurrencyCode() == CurrencyCode)
            {
                return C;
            }
        }
        return GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(std::string Country)
    {
        Country = MyStringLib::CapitalizeAllString(Country);
        std::vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

        for (const clsCurrency &C : vCurrencies)
        {
            if (MyStringLib::CapitalizeAllString(C.GetCountry()) == Country)
            {
                return C;
            }
        }
        return GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(const std::string &CurrencyCode)
    {
        clsCurrency C = FindByCode(CurrencyCode);
        return (!C.IsEmpty());
    }

    static std::vector<clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrenciesDataFromFile();
    }
};