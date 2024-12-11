const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const path = require('path');
const db = require('./config/db'); // Import the database connection
const isAuthenticated = require('./auth'); // Adjust the path to your authentication middleware
const recipientsRouter = require('./routes/recipientsRoute'); // Import your recipients route

const app = express();

// Configure sessions
app.use(
    session({
        secret: 'your_secret_key', // Change this to a strong, random string
        resave: false,
        saveUninitialized: true,
    })
);

// Middleware for parsing JSON and URL-encoded data
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Set up views and static files
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
app.use(express.static(path.join(__dirname, 'public')));

// Import and use your routes
const loginRouter = require('./routes/loginRoute');
const dashboardRouter = require('./routes/dashboardRoute'); // Import your dashboard route
const donors = require('./routes/donorsRoute');

// app.use('/', indexRouter);
app.use('/', loginRouter);

// Use isAuthenticated middleware for protected routes
app.get('/dashboard', isAuthenticated, dashboardRouter);

app.get('/donors', isAuthenticated, donors);

app.get('/add', isAuthenticated, donors);
app.post('/add',isAuthenticated,donors);


app.use('/recipients', isAuthenticated, recipientsRouter);

// Start the server
const port = process.env.PORT || 3000;
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});

