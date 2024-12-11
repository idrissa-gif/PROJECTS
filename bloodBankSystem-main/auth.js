
function isAuthenticated(req, res, next) {
    // Check if the user is authenticated based on your logic
    if (req.session.user) {
        // User is authenticated, allow them to proceed
        console.log("successful");
        next();
    } else {
        // User is not authenticated, redirect to the login page or handle the situation
        console.log("failed");
        res.redirect('/login'); // For example, redirect to the login page
    }
}
module.exports = isAuthenticated;
