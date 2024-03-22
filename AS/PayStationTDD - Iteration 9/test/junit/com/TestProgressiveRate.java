package junit.com;

import org.junit.*;
import static org.junit.Assert.*;

public class TestProgressiveRate {

    RateStrategy rS;
    @Before
    public void setUp() {
        rS = new ProgressiveRate();
    }

    @Test
    public void testFirstHour() {
        assertEquals(60, rS.calculateTime(150));
    }

    @Test
    public void testSecondHour() {
        assertEquals(120, rS.calculateTime(350));
    }

    @Test
    public void testThirdHour() {
        assertEquals(180, rS.calculateTime(650));
    }
}
