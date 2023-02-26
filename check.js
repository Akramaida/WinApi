const check = require('bindings')('check');
const express = require('express');

const app = express();
const users = check.check();
app.set('view engine', 'ejs');
app.set('views', './views');
app.use(express.text());
app.use(express.urlencoded());

console.log("Server started");

app.get('/', function (_req, res) {
    res.render('html');
});

app.post('/', function (_req, res) {

    let formData = _req.body.username;
    const isPresent = false;
    var i;

    for (i = 0; i < 5; i++) {
        if (users[i] === formData) {
            isPresent = true;
        }
    }

    if (isPresent) {
        res.render('1', { formData });
    } else {
        res.render('2', { formData });
    }

});

const port = 3000;
app.listen(port);
