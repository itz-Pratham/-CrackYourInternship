class Solution {
public:
    string intToRoman(int num) {
        string ones_place[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens_place[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns_place[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths_place[]={"","M","MM","MMM"};
        
        return ths_place[num/1000] + hrns_place[(num%1000)/100] + tens_place[(num%100)/10] + ones_place[num%10];
    }
};