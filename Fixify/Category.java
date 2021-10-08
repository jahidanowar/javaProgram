/* 
 * 6. Demonstration of Abstract Class and abstract method
 * Reg: 2147033
 * @author Jahid A

*/

package Fixify;

abstract class CategoryInfo {
    abstract String getName();
}

public class Category extends CategoryInfo {

    String name;

    public Category(String name) {
        this.name = name;
    }

    String getName() {
        return name;
    }
}
