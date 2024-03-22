package junit.com;

public class ProgressiveRate implements RateStrategy{
    public ProgressiveRate(){
    }

    public int calculateTime(int paidSoFar){
        int time;
        if (paidSoFar >= 350){
            paidSoFar -= 350;
            time = 120 + (paidSoFar / 5);
        }
        else if (paidSoFar >= 150) {
            paidSoFar -= 150;
            time = 60 + (paidSoFar * 3 / 10);
        }
        else {
            time = paidSoFar * 2 / 5;
        }

        return time;
    }
}
