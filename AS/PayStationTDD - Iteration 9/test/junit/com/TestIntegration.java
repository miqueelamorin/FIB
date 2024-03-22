package junit.com;

import org.junit.*;
import static org.junit.Assert.*;

public class TestIntegration {
    PayStation ps;
    /** Fixture for pay station testing. */
    @Test
    public void testBoston() throws IllegalCoinException {
        RateStrategy rS = new ProgressiveRate();
        ps = new PayStationImpl(rS);
        ps.addPayment(5);
        assertEquals(2, ps.readDisplay());
    }

    @Test
    public void testNewYork() throws IllegalCoinException {
        RateStrategy rS = new LinearRate();
        ps = new PayStationImpl(rS);
        ps.addPayment(5);
        assertEquals(2, ps.readDisplay());
    }
}
