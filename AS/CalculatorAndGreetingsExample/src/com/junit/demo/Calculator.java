package com.junit.demo;


public class Calculator {
		  
		 public double multiply(double a, double b) {
		  return a * b;
		 }
		  
		 public double divide(double a, double b) {
			 if (b == 0) {
				 throw new ArithmeticException();
			 }
			 return a / b;
		 }

		 public double add(double a, double b){
			 return a+b;
		 }

		 public double subtract(double a, double b){
			 if (b > a) throw new ArithmeticException();
			 return a-b;
		 }

		 public int factorial(int a) throws nEsNegatiu {
			 if (a == 0) return 1;
			 else if (a < 0) throw new nEsNegatiu();
			 int value = a;
			 for (int i = 1; i < value; i++) {
				 a *= i;
			 }
			 return a;
		 }
}

class nEsNegatiu extends ArithmeticException {
}
