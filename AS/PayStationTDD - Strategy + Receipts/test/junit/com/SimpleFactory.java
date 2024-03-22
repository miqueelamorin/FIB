package junit.com;

public class SimpleFactory implements PayStationFactory{
    public SimpleFactory() {
    }

    public Receipt createReceipt(int parkTime) {
        return new StandardReceipt(parkTime);
    }

    public RateStrategy createRateStrategy() {
        return new One2OneRateStrategy();
    }
}
