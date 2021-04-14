const express = require('express')
var bodyParser = require('body-parser');
var mysql = require('mysql');
const app = express()
const port = 3000

var jsonParser = bodyParser.json();


var pool = mysql.createPool({
    connectionLimit: 10,
    host: 'localhost',
    user: 'localuser',
    password: '123456',
    database: 'rest_api_c++'
});

app.get('/', (req, res) => {
    res.send('Hello World!')
})

app.get('/user', (req, res) => {
    pool.getConnection(function (err, connection) {
        if (err) throw err;
        connection.query('SELECT * FROM `user`', function (error, results, fields) {
            connection.release();
            res.writeHead(200, { 'Content-Type': 'text/html' });
            for (var i = 0; i < results.length; i++) {
                res.write(results[i].id + " " + results[i].name + " " + results[i].last_name + " " + results[i].email + " " + results[i].password + "\n");
            }
            res.end();
            if (error) throw error;
        });
    });
})

app.post('/user', jsonParser, (req, res) => {
    pool.getConnection(function (err, connection) {
        if (err) throw err;
        var sql = 'INSERT INTO `user` (`name`, `last_name`, `email`, `password`) VALUES (\'' + req.body.name + '\', \'' + req.body.last_name + '\', \'' + req.body.email + '\', \'' + req.body.password + '\')';
        console.log(sql);
        connection.query(sql, function (error, results, fields) {
            connection.release();
            res.writeHead(200, { 'Content-Type': 'text/html' });
            var num = results.insertId;
            res.write(num.toString());
            res.end();
            if (error) throw error;
        });
    });
})

app.put('/user', jsonParser, (req, res) => {
    pool.getConnection(function (err, connection) {
        if (err) throw err;
        var sql = 'UPDATE `user` SET `name`=\'' + req.body.name + '\',`last_name`=\'' + req.body.last_name + '\',`email`=\'' + req.body.email + '\',`password` = \'' + req.body.password + '\' WHERE `user`.`id` = \'' + req.body.id + '\''
        console.log(sql);
        connection.query(sql, function (error, results, fields) {
            connection.release();
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.write('Edited');
            res.end();
            if (error) throw error;
        });
    });
})

app.delete('/user', jsonParser, (req, res) => {
    pool.getConnection(function (err, connection) {
        if (err) throw err;
        var sql = 'DELETE FROM `user` WHERE `user`.`id` = \'' + req.body.id + '\''
        console.log(sql);
        connection.query(sql, function (error, results, fields) {
            connection.release();
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.write('Deleted');
            res.end();
            if (error) throw error;
        });
    });
})

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})
