const express = require('express');
const bodyParser = require('body-parser');
const sqlite3 = require('sqlite3').verbose();

const app = express();
const port = 3000;
app.use(bodyParser.json());

// Open SQLite database
const db = new sqlite3.Database('sensor_data_2.db', (err) => {
  if (err) {
    console.error('Failed to open database:', err.message);
  } else {
    console.log('Connected to the SQLite database.');

    // Create a table to store sensor data if it doesn't exist
    db.run('CREATE TABLE IF NOT EXISTS sensor_data_2 (id INTEGER PRIMARY KEY AUTOINCREMENT, position TEXT, value INTEGER, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP)');
  }
});
/*
app.get('/retrieve-data', (req, res) => {
  const retrieveQuery = 'SELECT json_data FROM sensor_data_1';

  db.all(retrieveQuery, [], (err, rows) => {
    if (err) {
      console.error('Failed to retrieve data from database:', err.message);
      res.status(500).send('Internal Server Error');
    } else {
      // Loop through the rows and parse each JSON string
      const jsonDataArray = rows.map(row => JSON.parse(row.json_data));

      // Now you can access individual fields in the jsonDataArray
      jsonDataArray.forEach(jsonData => {
        console.log('Top:', jsonData.top);
        console.log('Left:', jsonData.left);
        // Add more fields as needed
      });

      res.send('Data retrieved successfully');
    }
  });
});
*/

app.post('/sensor-data', (req, res) => {
  const sensorData = req.body;
const jsonString = JSON.stringify(sensorData);

//const jsonDataArray = sensorData.map(sensorData => JSON.parse(sensorData));

      // Now you can access individual fields in the jsonDataArray
      //sensorData.forEach(sensorData => {
        //console.log('Top:', sensorData.top);
        //console.log('Left:', sensorData.left);})

  console.log('Received sensor data:', `${sensorData.top}`, jsonString);//, jsonString.sensorData.${{"top"}`);//.top );
//insertSensorData('top', 
  // Insert sensor data into the SQLite database
  //insertSensorData('top', `${sensorData.top}`);
  //insertSensorData('left', sensorData.left);
  //insertSensorData('middle', sensorData.middle);
  //insertSensorData('bottom', sensorData.bottom);
  //insertSensorData('right', sensorData.right);
  //insertSensorData('current', sensorData.current);
  res.send('Data received successfully');});
function insertSensorData(position, value) {
  // Insert sensor data into the SQLite database
  const insertQuery = 'INSERT INTO sensor_data_2 (position, value) VALUES (?, ? )';

  db.run(insertQuery, [position, value], function (err) {
    if (err) {
      console.error(`Failed to insert ${position} data into database:`, err.message);
    } else {
      console.log("success")//`${position} data inserted into SQLite database.`);
    }
  });
}

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
