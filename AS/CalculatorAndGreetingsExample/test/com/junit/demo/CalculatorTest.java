package com.junit.demo;

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
 
public class CalculatorTest {

 private Calculator calc;

 @Before
 public void setUp() throws Exception {
  calc = new Calculator();
 }

 @After
 public void tearDown() throws Exception {
  calc = null;
 }

 @Test
 public void testMultiply() {
  double result = calc.multiply(2.5, 100);
  assertEquals(250, result, 0);
 }

 @Test
 public void testDivide() {
  double result = calc.divide(100, 10);
  assertEquals(10, result, 0);

 }

 @Test
 public void testDivideWithTolerance() {
  double result = calc.divide(345, 100);
  assertEquals(3.4, result, 0.1);

 }

 @Test(expected = ArithmeticException.class)
 public void testDivideByZero() {
  calc.divide(100.5, 0);
 }

 @Test
 public void testAdd() {
  double result = calc.add(2.5, 100);
  assertEquals(102.5, result, 0);
 }

 @Test
 public void testSubtract() {
  double result = calc.subtract(100, 2.5);
  assertEquals(97.5, result, 0);
 }

 @Test(expected = ArithmeticException.class)
 public void testSubtractWithTolerance() {
  calc.subtract(2.5, 100);
 }

 @Test
 public void testFactorialZero() {
  int result = calc.factorial(0);
  assertEquals(1, result, 0);
 }

 @Test(expected = nEsNegatiu.class)
 public void testFactorialNegative() throws nEsNegatiu {
  calc.factorial(-1);
 }

 @Test
 public void testFactorial() throws nEsNegatiu {
  int result = calc.factorial(5);
  assertEquals(120, result, 0);
 }
}





