package junit.com;

import org.junit.Test;

import java.util.Date;

import static org.junit.Assert.assertEquals;

public class TestRevisionState {
    @Test
    public void testRevisionState(){
            State st = new Revision("Miquel");
            assertEquals("Should be in revised state", "Miquel", st.getStateInfo());
    }
}
