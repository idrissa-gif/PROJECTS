const express = require('express');
const router = express.Router();
const db = require('../config/db'); // Import the database connection
const bcrypt = require('bcrypt');

// GET request to render the login form
router.get(['/login','/'], (req, res) => {
    res.render('login'); // Assuming you're using template rendering (e.g., EJS)
});

// POST request to handle the login form submission
router.post(['/login','/'], (req, res) => {
    const { username, password } = req.body;

    // Query the database to find the user
    const query = 'SELECT * FROM users WHERE username = ?';
    db.query(query, [username], (err, results) => {
        if (err) {
            // Handle the database error
            return res.status(500).json({ error: 'Internal server error' });
        }

        if (results.length === 1) {
            const user = results[0];

            // Compare the hashed password from the database with the provided password
            bcrypt.compare(password, user.password, (err, passwordMatch) => {
                if (err) {
                    return res.status(500).json({ error: 'Internal server error' });
                }

                if (passwordMatch) {
                    // Set req.user with user information
                    req.session.user = { id: user.id, username: user.username };
                    
                    // Redirect to the index
                    res.render('index');
                   
                } else {
                    // Incorrect username or password
                    return res.status(401).json({ error: 'Incorrect username or password' });
                }
            });
        } else {
            // User not found
            return res.status(401).json({ error: 'Incorrect username or password' });
        }
    });
});


module.exports = router;

