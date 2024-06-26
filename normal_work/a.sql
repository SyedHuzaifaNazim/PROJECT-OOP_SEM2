CREATE DATABASE crime_db;
USE crime_db;

CREATE TABLE crimes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    district VARCHAR(100),
    area VARCHAR(100),
    description TEXT,
    number_of_people INT,
    type ENUM('Snatching', 'Harassment', 'Robbery'),
    vehicle_type VARCHAR(100),
    vehicle_no VARCHAR(100),
    snatched_item VARCHAR(100),
    robbed_item VARCHAR(100),
    physical BOOLEAN
);
