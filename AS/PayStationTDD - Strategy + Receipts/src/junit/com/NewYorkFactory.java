package junit.com;

public class NewYorkFactory implements PayStationFactory{
    public NewYorkFactory() {
    }

    public Receipt createReceipt(int parkTime) {
        return new StandardReceipt(parkTime);
    }

    public RateStrategy createRateStrategy() {
        return new LinearRateStrategy();
    }
}
