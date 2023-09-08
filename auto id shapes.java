//AutoID to Shapes 


import java.util.Date;

class Shape {
    private static int nextAutoID = 1;

    private int shapeID;
    private Date creationTimestamp;

    public Shape() {
        shapeID = nextAutoID++;
        creationTimestamp = new Date();
    }

    public int getShapeID() {
        return shapeID;
    }

    public Date getCreationTimestamp() {
        return creationTimestamp;
    }

    @Override
    public String toString() {
        return "Shape{" +
                "shapeID=" + shapeID +
                ", creationTimestamp=" + creationTimestamp +
                '}';
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "shapeID=" + getShapeID() +
                ", creationTimestamp=" + getCreationTimestamp() +
                ", length=" + length +
                ", width=" + width +
                '}';
    }
}

class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    @Override
    public String toString() {
        return "Square{" +
                "shapeID=" + getShapeID() +
                ", creationTimestamp=" + getCreationTimestamp() +
                ", side=" + side +
                '}';
    }
}

class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "shapeID=" + getShapeID() +
                ", creationTimestamp=" + getCreationTimestamp() +
                ", base=" + base +
                ", height=" + height +
                '}';
    }
}

public class ShapeLinkedList {
    private static class Node {
        Shape shape;
        Node next;

        Node(Shape shape) {
            this.shape = shape;
            this.next = null;
        }
    }

    private Node head;

    public void addShape(Shape shape) {
        Node newNode = new Node(shape);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public void displayShapes() {
        Node current = head;
        while (current != null) {
            System.out.println(current.shape);
            current = current.next;
        }
    }

    public static void main(String[] args) {
        ShapeLinkedList shapeList = new ShapeLinkedList();

        Rectangle rectangle = new Rectangle(5, 10);
        Square square = new Square(7);
        Triangle triangle = new Triangle(8, 12);

        shapeList.addShape(rectangle);
        shapeList.addShape(square);
        shapeList.addShape(triangle);

        shapeList.displayShapes();
    }
}
