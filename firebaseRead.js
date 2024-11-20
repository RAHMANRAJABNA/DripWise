import { getDatabase, ref, onValue } from "firebase/database";

const db = getDatabase();
const moistureRef = ref(db, 'moistureData/sensor_1');
const scheduleRef = ref(db, 'wateringSchedule/dailySchedule');

// Mendapatkan data kelembapan
onValue(moistureRef, (snapshot) => {
  const data = snapshot.val();
  console.log("Moisture Level:", data.moistureLevel);
  console.log("Timestamp:", data.timestamp);
});

// Mendapatkan data jadwal penyiraman
onValue(scheduleRef, (snapshot) => {
  const data = snapshot.val();
  console.log("Start Time:", data.startTime);
  console.log("Duration:", data.duration);
});
