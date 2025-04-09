#include <iostream>
#include <string>

namespace std
{
    class Solution
    {
    public:
        string intToBinary(int num)
        {
            if (num == 0)
                return "";

            std::string binary = "";

            while (num != 0)
            {
                binary += std::to_string(num % 2);
                num /= 2;
            }

            return binary;
        }

        string addBinary(string a, string b)
        {
            int conv = 1;
            int int_a = 0;
            int int_b = 0;

            for (int i = a.length() - 1; i >= 0; i--)
            {
                if (a[i] == 1)
                {
                    if (conv == 1)
                        int_a++;
                    else
                    {
                        int_a += conv;
                    }
                }
                conv = conv + conv;
            }

            conv = 1;

            for (int i = b.length() - 1; i >= 0; i--)
            {
                if (b[i] == 1)
                {
                    if (conv == 1)
                        int_b++;
                    else
                    {
                        int_b += conv;
                    }
                }
                conv = conv + conv;
            }

            return intToBinary(int_a + int_b);
        }
    };
}