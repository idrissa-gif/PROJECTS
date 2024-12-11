import java.sql.ResultSet;
import java.sql.SQLException;

import static java.lang.System.exit;

public class BookStoreController {
    BookStoreModel model;
    BookStoreView view;
    /**
     * The controller constructor takes a model and view as parameters
     * as it will act as the mediator between them.
     * @param model the model object that will store the book's info
     * @param view the view object that the user will see
     **/
    public BookStoreController(BookStoreModel model , BookStoreView view) {
        this.model = model;
        this.view = view;
    }
    /**
     * This method will allow the controller to take the choice given by
     * the user to the view :
     * 1. ADD A NEW BOOK
     * 2. DELETE A BOOK
     * 3. VIEW THE DETAILS OF SPECIFIC BOOK
     * 4. VIEW ALL THE BOOKS
     * 5. EXIT
     **/
   public void getMenu() throws SQLException {
        while(true)
        {
            int ch = view.menu();
            switch (ch) {
                case 1 -> getAddBook();
                case 2 -> getDeleteBook();
                case 3 -> getDetailsOfspecificBook();
                case 4 -> getDetailsOfAllBooks();
                case 5 -> exit(0);
            }

        }
   }
    /**
     * Through this method, the controller will tell the model to add
     * the book info provide by the view to store in the bookStore database.
     **/
    public void getAddBook()
   {
       view.setBookInfo();
       boolean added = model.addBook(view);
       view.updateViewAfterAddBook(added);
   }
    /**
     * Through this method, the controller will tell the model to delete
     * the book info provide by the view to store in the  bookStore database.
     **/
   public void getDeleteBook()
   {
       view.setBookTitle();
       boolean deleted = model.deleteBook(view);
       view.updateViewAfterDeleteBook(deleted);
   }
    /**
     * Through this method, the controller will tell the model to get the detail info of specific book
     * base on it title provide by the view.
     **/
    public void getDetailsOfspecificBook() throws SQLException {
        view.setBookTitle();
        ResultSet rs = model.viewDetailsOfSpecificBook(view);
        view.updateViewAfterViewOfSpecificBook(rs);
    }
    /**
     * Through this method, the controller will tell the model to get the details of all the book
     * in the BookStore database
     **/
    public void getDetailsOfAllBooks() throws SQLException {
        ResultSet rs = model.viewAllBooks();
        view.updateViewAfterViewAllBooks(rs);
    }
}
