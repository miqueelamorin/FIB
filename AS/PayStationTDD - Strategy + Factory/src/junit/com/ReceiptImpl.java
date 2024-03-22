package junit.com;

public abstract class ReceiptImpl implements Receipt{
    public final int value;
    public ReceiptImpl(int value) {
        this.value = value;
    }
    public int value() {
        return value;
    }

    public String print() {
        String receiptContent = "----------------------------------";
        receiptContent = receiptContent + "\n";
        receiptContent = receiptContent + "-------- PARKING RECEIPT --------";
        receiptContent = receiptContent + "\n";
        receiptContent = receiptContent + "         Value " + value + " minutes";
        receiptContent = receiptContent + "\n";
        receiptContent = additionalPrint(receiptContent);
        receiptContent = receiptContent + "----------------------------------";
        return receiptContent;
    }

    public abstract String additionalPrint(String receiptContent);
}