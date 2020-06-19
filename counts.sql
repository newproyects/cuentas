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
) ENGINE=InnoDB AUTO_INCREMENT=113 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `arch`
--

LOCK TABLES `arch` WRITE;
/*!40000 ALTER TABLE `arch` DISABLE KEYS */;
INSERT INTO `arch` VALUES (101,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(102,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(103,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n      //cout << d.insd(q) << endl;\n\n      Table x(3,2*strlen(d.t[2])+1);\n      strcpy(x.t[0],d.t[0]);\n      strcpy(x.t[1],d.t[1]);\n      mysql_real_escape_string(mc.con,x.t[2],d.t[2],strlen(d.t[2]));\n      cout << x.t[2] << endl;\n\n      //cout << x.insd(q) << endl;\n      mysql_query(mc.con,x.insd(q));\n      //cout << mc.indata(q,d) << endl;\n      //if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      //else cout << \"Archivo ingresado\\n\";\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n'),(104,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n'),(105,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(106,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n'),(107,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n'),(108,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n\n      q=\"select data from arch where id=105\";\n\n      q=mc.outdata(q);\n      cout << q << endl;\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n'),(109,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(110,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(111,148,'Makefile',_binary 'a: main.o\n	g++ main.o mycon.o strutil.o -o a -L/usr/local/lib -lmysqlclient\n	rm *.o\n\nmain.o: main.cpp mycon.cpp mycon.h strutil.cpp strutil.h\n	g++ -c main.cpp -I/usr/include/mysql\n	g++ -c  mycon.cpp -I/usr/include/mysql\n	g++ -c  strutil.cpp -I/usr/include/mysql\n'),(112,148,'main.cpp',_binary '#include \"mycon.h\"\n\nint main(){\n  char c[]=\"select id from user where name=\'%s\' and pswd=\'%s\'\";\n  Table data(10,40);\n  MyCon mc(\"localhost\",\"root\",\"tabladelfin\",\"counts\");\n  char result[10];\n  FILE *f;\n\n  cout << \"ingresar nombre: \";\n  cin.getline(data.t[0],10,\'\\n\');\n  fflush(stdin);\n  cout << \"ingresar contraseña: \";\n  cin.getline(data.t[1],8,\'\\n\');\n  cout << \"ingresar archivo: \";\n  cin.getline(data.t[2],20,\'\\n\');\n  \n  \n  if(mc.queryd(c,data)) mc.fail();\n\n  mc.outpoint(result);\n\n  cout << \"id: \" << (strcmp(result,\"\")==0 ? \"error de acceso\" : result) << endl;\n\n  if(strcmp(result,\"\")!=0){\n\n    /*\n    Table user(10,40);\n    cout << \"tabla de usuarios\\n\";\n    mc.query(\"select * from user\");\n    mc.outtable(user);\n    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;\n    */\n    \n    f=fopen(data.t[2],\"rb\");\n    if(f==NULL) cout << \"Archivo inexistente\" << endl;\n    else{\n      cout << \"Arcbriendo archivo...\" << endl;\n      fseek(f,0,SEEK_END);\n      int fl=ftell(f);\n      Table d(3,fl+1);\n      fseek(f,0,SEEK_SET);\n      fread(d.t[2],1,fl,f);\n      fclose(f);\n\n      //cout << d.t[2] << endl;\n      \n      strcpy(d.t[0],result);\n      strcpy(d.t[1],data.t[2]);\n\n      char *q=\"insert into arch(id_user,name_arch,data) values(\'%s\',\'%s\',\'%s\')\";\n\n      if(mc.indata(q,d)) cout << \"error de ingreso de archivo\\n\";\n      else cout << \"Archivo ingresado\\n\";\n\n      q=\"select data from arch where id_arch=105\";\n\n      q=mc.outdata(q);\n      cout << q << endl;\n    }\n  }\n  \n  mc.close();\n  return 0;\n}\n');
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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=166 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (148,'angel','pollo'),(149,'lugo','sks'),(150,'ksks','lwlw'),(151,'benito','camela'),(153,'lola','lssl'),(155,'kosko','koekozd'),(161,'kaksos','skaks'),(162,'tito','camotit'),(163,'jorge','curioso'),(164,'rumeno','gurrume'),(165,'tiko','riko');
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

-- Dump completed on 2020-06-18 18:43:10
