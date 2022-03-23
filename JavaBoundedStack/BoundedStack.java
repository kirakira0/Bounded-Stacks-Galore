package JavaBoundedStack;

public class BoundedStack {

    final int MAX_CAPACITY = 256;
    final int MAX_ITEM_LENGTH = 128;

    int size;
    int capacity;
    String[] items;

    public BoundedStack(int capacity) {
        if (capacity < 0 || capacity > MAX_CAPACITY) {
            throw new IllegalArgumentException(
                    "Capcity is too small or too large (must be between 0 and 256, inclusive.)");
        }
        this.capacity = capacity;
        this.size = 0;
        this.items = new String[capacity];
    }

    public void push(String item) throws Exception {
        this.validateItemLength(item);
        this.validateNotFull();
        this.size += 1;
        this.items[this.size - 1] = item;
    }

    public String pop() throws Exception {
        this.validateNotEmpty();
        this.size -= 1;
        return this.items[size + 1];

    }

    public String peek() throws Exception {
        this.validateNotEmpty();
        return this.items[size];
    }

    public int size() {
        return this.size;
    }

    private void validateItemLength(String item) {
        if (item.length() <= 0 || item.length() > MAX_ITEM_LENGTH) {
            throw new IllegalArgumentException("Item length is too small or too large");
        }
    }

    private void validateNotFull() throws Exception {
        if (this.size >= this.capacity)
            throw new Exception("Stack is full.");

    }

    private void validateNotEmpty() throws Exception {
        if (this.size == 0)
            throw new Exception("Stack is empty.");
    }
}