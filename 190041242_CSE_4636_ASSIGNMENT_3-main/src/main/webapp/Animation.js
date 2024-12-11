function ChangeOption()
{
    const add = document.getElementById("add");
    const remove = document.getElementById("remove");
    const show_content = document.getElementById("show_content");
    const update = document.getElementById("update");

    add.addEventListener("click", function(event) {
        window.location.href = "AddToCart.jsp";
    });
    remove.addEventListener("click", function(event) {

        window.location.href = "RemoveFromCart.jsp";
    });
    show_content.addEventListener("click", function(event) {
        window.location.href = "ShowShoppingCartContent.jsp";
    });
    update.addEventListener("click", function(event) {
        // event.preventDefault(); // prevent the default link behavior

        window.location.href = "UpdateCart.jsp";
    });
}
