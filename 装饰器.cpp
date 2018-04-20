// 顶层接口
public interface Shape {
    void draw();
    void f1();
    void f2();
}

// 抽象装饰器类
public abstract class ShapeDecorator implements Shape {
    protected Shape decoratedShape;

    public ShapeDecorator(Shape decoratedShape){
        this.decoratedShape = decoratedShape;
    }

    public void draw(){
        decoratedShape.draw();
    }

    public void f1(){
        decoratedShape.f1();
    }

    public void f2(){
        decoratedShape.f2();
    }
}

//一个实际的装饰器类
public class RedShapeDecorator extends ShapeDecorator {
    public RedShapeDecorator(Shape decoratedShape) {
        super(decoratedShape);
    }

    // 这个类只想增强一下draw()方法，不想变动其他的f1,f2方法，所以这个类只需要重写这个类即可
    public void draw() {
        decoratedShape.draw();
        setRedBorder(decoratedShape);
    }

    private void setRedBorder(Shape decoratedShape){
        System.out.println("Border Color: Red");
    }
}

//一个实际的装饰器类
public class RedShapeDecorator implements Shape {
    // 每多一个装饰器类，这里需要重复
    private Shape decoratedShape;

    public RedShapeDecorator(Shape decoratedShape) {
        this.decoratedShape = decoratedShape;
    }

    public void draw() {
        decoratedShape.draw();
        setRedBorder(decoratedShape);
    }

    private void setRedBorder(Shape decoratedShape){
        System.out.println("Border Color: Red");
    }

    //这个类仅仅想增强draw方法，但是因为实现的是顶层接口，不得不重写这个方法
    public void f1(){
        decoratedShape.f1();
    }

    //这个类仅仅想增强draw方法，但是因为实现的是顶层接口，不得不重写这个方法
    public void f2(){
        decoratedShape.f2();
    }
}