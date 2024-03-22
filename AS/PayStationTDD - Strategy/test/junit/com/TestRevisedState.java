package junit.com;

import org.junit.*;

import java.util.Date;

import static org.junit.Assert.*;

public class TestRevisedState {
    @Test
    public void testRevisedState(){
            State st = new Revised(new Date().toString());
            assertEquals("Should be in revised state", new Date().toString(), st.getStateInfo());
    }
}
