package junit.com;

public class One2One implements RateStrategy{
    public One2One(){
    }

    @Override
    public int calculateTime(int paidSoFar) {
        return paidSoFar;
    }
}
