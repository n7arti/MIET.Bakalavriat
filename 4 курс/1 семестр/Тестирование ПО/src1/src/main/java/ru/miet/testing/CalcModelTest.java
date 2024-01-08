package ru.miet.testing;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class CalcModelTest {

    @Test
    void sum() {
        CalcModel calcModel = new CalcModel();

        double result = calcModel.sum(12, 1.2);

        assertEquals(13.2, result);
    }

    @Test
    void subtract() {
        CalcModel calcModel = new CalcModel();

        double result = calcModel.subtract(12, 1.2);

        assertEquals(10.8, result);
    }

    @Test
    void multiply() {
        CalcModel calcModel = new CalcModel();

        double result = calcModel.multiply(12, 1.2);

        assertEquals(12 * 1.2, result);
    }

    @Test
    void divideCorrectTest() {
        CalcModel calcModel = new CalcModel();

        double result = calcModel.divide(12, 1.2);

        assertEquals(10, result);
    }

    @Test
    void divideZeroTest() {
        CalcModel calcModel = new CalcModel();

        Throwable thrown = assertThrows(ArithmeticException.class, () -> {
            calcModel.divide(12, 0);
        });

        assertNotNull(thrown);
    }
}