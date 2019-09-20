 #include <bits/stdc++.h>
using namespace std;
//examples:
int main() {
    char s[100], t[100];
    scanf("%*[0-9]%*[a-z]%[0-9]", s); //ignore any number of chars in range [0-9] then ignore any number of chars in range [a-z] then read any number of chars in range [0-9].
    scanf("%*5[0-9]%[a-zA-Z0-9]", s); //ignore first 5 digits then read any char in range [a-z] or [A-Z] or [0-9]
    scanf("%[^\n]", s); // read until the end of the line
    scanf("%[^-]-->%[^\n]", s, t); //read string1, string2 in "string1-->string2"
    scanf("%[abc12.]", s); //read string consists of letters {'a', 'b', 'c', '1', '2', '.'} until any other latter appears
}
//for more:
//https://regexr.com/
//http://www.gnu.org/software/libc/manual/html_node/String-Input-Conversions.html
//https://bytes.com/topic/c/answers/521077-scanf-information
//https://stackoverflow.com/questions/14873542/use-scanf-with-regular-expressions
