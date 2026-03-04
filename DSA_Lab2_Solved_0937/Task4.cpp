//1. The Function that Works : add()
//In C++, the + operator is specifically programmed to work with strings.If you have "Apple" and "Pie," add() will return "ApplePie".This is a special feature called Operator Overloading.
//
//2. The Functions that Fail : subtract(), multiply(), divide()
//These functions will cause the compiler to stop and throw an error.
//
//Why ? The computer does not know the logic for "subtracting" one word from another or "multiplying" two sentences.
//
//The Result : Your code will not even finish building.The compiler will report that operator-, operator*, and operator/ are not matches for the std::string type.