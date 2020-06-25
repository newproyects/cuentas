-- MySQL dump 10.13  Distrib 8.0.20, for Linux (x86_64)
--
-- Host: localhost    Database: counts
-- ------------------------------------------------------
-- Server version	8.0.20

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `arch`
--

CREATE USER program IDENTIFIED BY 'margorp';
GRANT ALL PRIVILEGES ON counts.* TO 'program' WITH GRANT OPTION;

DROP TABLE IF EXISTS `arch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `arch` (
  `id_arch` int NOT NULL AUTO_INCREMENT,
  `id_user` int NOT NULL,
  `name_arch` varchar(40) NOT NULL,
  `data` mediumblob NOT NULL,
  PRIMARY KEY (`id_arch`),
  KEY `id_user` (`id_user`),
  CONSTRAINT `arch_ibfk_1` FOREIGN KEY (`id_user`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=119 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `arch`
--

LOCK TABLES `arch` WRITE;
/*!40000 ALTER TABLE `arch` DISABLE KEYS */;
INSERT INTO `arch` VALUES (114,100,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(115,100,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  FILE *f;\n  Table d(2,10);\n\n  strcpy(d.t[0],\"100\");\n  strcpy(d.t[1],\"main.cpp\");\n  \n\n  f=fopen(d.t[1],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table x(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(x.t[2],1,fl,f);\n      fclose(f);\n\n      \n      strcpy(x.t[0],d.t[0]);\n      strcpy(x.t[1],d.t[1]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,x,3)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n    }\n  \n  return 0;\n}\n name=\"c\�'),(116,100,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(117,100,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(118,100,'counts.sql',_binary '-- MySQL dump 10.13  Distrib 8.0.20, for Linux (x86_64)\n--\n-- Host: localhost    Database: counts\n-- ------------------------------------------------------\n-- Server version	8.0.20\n\n/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;\n/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;\n/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;\n/*!50503 SET NAMES utf8mb4 */;\n/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;\n/*!40103 SET TIME_ZONE=\'+00:00\' */;\n/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;\n/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;\n/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE=\'NO_AUTO_VALUE_ON_ZERO\' */;\n/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;\n\n--\n-- Table structure for table `arch`\n--\n\nCREATE USER program IDENTIFIED BY \'margorp\';\nGRANT ALL PRIVILEGES ON counts.* TO \'program\' WITH GRANT OPTION;\n\nDROP TABLE IF EXISTS `arch`;\n/*!40101 SET @saved_cs_client     = @@character_set_client */;\n/*!50503 SET character_set_client = utf8mb4 */;\nCREATE TABLE `arch` (\n  `id_arch` int NOT NULL AUTO_INCREMENT,\n  `id_user` int NOT NULL,\n  `name_arch` varchar(40) NOT NULL,\n  `data` mediumblob NOT NULL,\n  PRIMARY KEY (`id_arch`),\n  KEY `id_user` (`id_user`),\n  CONSTRAINT `arch_ibfk_1` FOREIGN KEY (`id_user`) REFERENCES `user` (`id`)\n) ENGINE=InnoDB AUTO_INCREMENT=113 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;\n/*!40101 SET character_set_client = @saved_cs_client */;\n\n--\n-- Dumping data for table `arch`\n--\n\nLOCK TABLES `arch` WRITE;\n/*!40000 ALTER TABLE `arch` DISABLE KEYS */;\n/*!40000 ALTER TABLE `arch` ENABLE KEYS */;\nUNLOCK TABLES;\n\n--\n-- Table structure for table `user`\n--\n\nDROP TABLE IF EXISTS `user`;\n/*!40101 SET @saved_cs_client     = @@character_set_client */;\n/*!50503 SET character_set_client = utf8mb4 */;\nCREATE TABLE `user` (\n  `id` int NOT NULL AUTO_INCREMENT,\n  `name` varchar(10) NOT NULL,\n  `pswd` varchar(8) NOT NULL,\n  PRIMARY KEY (`id`)\n) ENGINE=InnoDB AUTO_INCREMENT=101 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;\n/*!40101 SET character_set_client = @saved_cs_client */;\n\n--\n-- Dumping data for table `user`\n--\n\nLOCK TABLES `user` WRITE;\n/*!40000 ALTER TABLE `user` DISABLE KEYS */;\nINSERT INTO `user` VALUES (0,\'root\',\'toor\');\n/*!40000 ALTER TABLE `user` ENABLE KEYS */;\nUNLOCK TABLES;\n/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;\n\n/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;\n/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;\n/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;\n/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;\n/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;\n/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;\n/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;\n\n-- Dump completed on 2020-06-21 16:34:36\ned</flag>\�');
/*!40000 ALTER TABLE `arch` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(10) NOT NULL,
  `pswd` varchar(8) NOT NULL,
  `active` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=101 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (0,'root','toor',0);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-06-25 12:47:17
