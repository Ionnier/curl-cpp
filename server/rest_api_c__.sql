-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 14, 2021 at 02:14 PM
-- Server version: 10.4.18-MariaDB
-- PHP Version: 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rest_api_c++`
--

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  `last_name` varchar(20) NOT NULL,
  `email` varchar(30) NOT NULL,
  `password` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `name`, `last_name`, `email`, `password`) VALUES
(5, 'asd', 'bsd', 'csd', 'dsd'),
(6, 'asd', 'bsd', 'csd', 'dsd'),
(7, 'asd', 'bsd', 'csd', 'dsd'),
(8, 'asd', 'bsd', 'csd', 'dsd'),
(9, 'asd', 'bsd', 'csd', 'dsd'),
(10, 'asd', 'bsd', 'csd', 'dsd'),
(11, 'asd', 'bsd', 'csd', 'dsd'),
(12, 'asd', 'bsd', 'csd', 'dsd'),
(13, 'asd', 'bs', 'c', 'd'),
(14, 'asd', 'bs', 'c', 'd'),
(15, 'asd', 'bs', 'c', 'd'),
(16, 'asd', 'bs', 'c', 'd'),
(17, 'asd', 'bs', 'c', 'd'),
(18, 'asd', 'bs', 'c', 'd'),
(19, 'asd', 'bs', 'c', 'd'),
(20, 'asd', 'bs', 'c', 'd'),
(21, 'asd', 'bs', 'c', 'd');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
