-- MySQL dump 10.13  Distrib 5.5.62, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: esaticbiblio
-- ------------------------------------------------------
-- Server version	5.5.62-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `adherent`
--

DROP TABLE IF EXISTS `adherent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `adherent` (
  `numCE` varchar(40) NOT NULL,
  `nom` varchar(40) NOT NULL,
  `prenom` varchar(40) NOT NULL,
  `classe` varchar(20) NOT NULL,
  `dateInscription` datetime NOT NULL,
  `dateSuppression` datetime DEFAULT NULL,
  PRIMARY KEY (`numCE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `adherent`
--

LOCK TABLES `adherent` WRITE;
/*!40000 ALTER TABLE `adherent` DISABLE KEYS */;
INSERT INTO `adherent` VALUES ('18-ESATIC0044DA','DIAKITE','IBN TIESSAMOU','MASTER 1 SIGL','2019-05-05 21:21:00',NULL),('CI0115290468','DIAKITE','SOUMAILA','MASTER 1 BDGL','2019-05-05 22:26:55',NULL);
/*!40000 ALTER TABLE `adherent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emprunt`
--

DROP TABLE IF EXISTS `emprunt`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emprunt` (
  `id` smallint(6) NOT NULL AUTO_INCREMENT,
  `numCE` varchar(40) NOT NULL,
  `identifiant` varchar(40) NOT NULL,
  `nbrelivre` smallint(6) NOT NULL,
  `dateE` datetime NOT NULL,
  `dateD` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_numCE` (`numCE`),
  KEY `fk_identifiant` (`identifiant`),
  CONSTRAINT `fk_identifiant` FOREIGN KEY (`identifiant`) REFERENCES `livre` (`identifiant`),
  CONSTRAINT `fk_numCE` FOREIGN KEY (`numCE`) REFERENCES `adherent` (`numCE`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emprunt`
--

LOCK TABLES `emprunt` WRITE;
/*!40000 ALTER TABLE `emprunt` DISABLE KEYS */;
INSERT INTO `emprunt` VALUES (1,'18-ESATIC0044DA','web1',1,'2019-05-05 23:11:14',NULL),(2,'CI0115290468','web1',1,'2019-05-05 23:12:13','2019-05-05 23:23:19'),(3,'CI0115290468','web1',1,'2019-05-06 10:55:22',NULL);
/*!40000 ALTER TABLE `emprunt` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `livre`
--

DROP TABLE IF EXISTS `livre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `livre` (
  `identifiant` varchar(40) NOT NULL,
  `nom` varchar(40) NOT NULL,
  `auteur` varchar(40) NOT NULL,
  `nbreexemplaire` smallint(6) DEFAULT '0',
  `dateC` datetime NOT NULL,
  `dateSupp` datetime DEFAULT NULL,
  PRIMARY KEY (`identifiant`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `livre`
--

LOCK TABLES `livre` WRITE;
/*!40000 ALTER TABLE `livre` DISABLE KEYS */;
INSERT INTO `livre` VALUES ('CppMathieu','Apprenez C++','MATHIEU NEBRA',10,'2019-05-05 14:44:46',NULL),('web1','Apprenez HTML5/CSS3','Mathieu NÃ©bra',9,'2019-05-05 22:17:25',NULL);
/*!40000 ALTER TABLE `livre` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-05-12  0:29:09
