package junit.com;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestLinearRate {

    RateStrategy rS;
    @Before
    public void setUp() {
        rS = new LinearRate();
    }

    @Test
    public void testFirstHour() {
        assertEquals(60, rS.calculateTime(150));
    }

    @Test
    public void testSecondHour() {
        assertEquals(140, rS.calculateTime(350));
    }

    @Test
    public void testThirdHour() {
        assertEquals(260, rS.calculateTime(650));
    }
}
