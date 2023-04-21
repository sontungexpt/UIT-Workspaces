import { enablePromise, openDatabase, SQLiteDatabase } from 'react-native-sqlite-storage';
// const tableName = 'db_7_4';

enablePromise(true);

interface Student {
  id: string;
  name: string;
  description: string;
  avatarLink: string;
}

export const getDBConnection = async () => {
  return openDatabase({ name: 'db_7_4.db', location: 'default' });
};

export const createAccountTable = async (db: SQLiteDatabase) => {
  // create table if not exists
  const query = `CREATE TABLE IF NOT EXISTS ACCOUNT(
      USERNAME TEXT PRIMARY KEY AUTOINCREMENT,
      PASSWORD TEXT,
    );`;

  await db.executeSql(query);
};

export const createClassesTable = async (db: SQLiteDatabase) => {
  // create table if not exists
  const query = `CREATE TABLE IF NOT EXISTS CLASS(
      ID TEXT PRIMARY KEY AUTOINCREMENT,
      NAME TEXT,
      DESCRIPTION TEXT,
      STUDENTCOUNT INTEGER,
    );`;

  await db.executeSql(query);
};
export const createClassTable = async (db: SQLiteDatabase) => {
  // create table if not exists
  const query = `CREATE TABLE IF NOT EXISTS STUDENT(
      ID TEXT PRIMARY KEY AUTOINCREMENT,
      NAME TEXT,
      DESCRIPTION TEXT,
      AVATAR TEXT,
    );`;

  await db.executeSql(query);
};
export const getStudentItems = async (
  db: SQLiteDatabase,
  tableName: string,
): Promise<Student[]> => {
  try {
    const studentItems: Student[] = [];
    const results = await db.executeSql(
      `SELECT rowid as id,value FROM ${tableName}`,
    );
    results.forEach(result => {
      for (let index = 0; index < result.rows.length; index++) {
        studentItems.push(result.rows.item(index));
      }
    });
    return studentItems;
  } catch (error) {
    console.error(error);
    throw Error('Failed to get student !!!');
  }
};

// export const saveTodoItems = async (db: SQLiteDatabase, studentItems: ToDoItem[]) => {
//   const insertQuery =
//     `INSERT OR REPLACE INTO ${tableName}(rowid, value) values` +
//     studentItems.map(i => `(${i.id}, '${i.value}')`).join(',');

//   return db.executeSql(insertQuery);
// };

// export const deleteTodoItem = async (db: SQLiteDatabase, id: number) => {
//   const deleteQuery = `DELETE from ${tableName} where rowid = ${id}`;
//   await db.executeSql(deleteQuery);
// };

export const deleteTable = async (db: SQLiteDatabase, tableName: string) => {
  const query = `drop table ${tableName}`;

  await db.executeSql(query);
};
