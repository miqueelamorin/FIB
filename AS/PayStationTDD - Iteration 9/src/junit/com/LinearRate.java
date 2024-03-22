package junit.com;

public class LinearRate implements RateStrategy{

    public LinearRate(){
    }
    @Override
    public int calculateTime(int paidSoFar){
        return paidSoFar / 5 * 2;
    }
}
