
#ifndef REGISTERACTIVITIES_DATE_H
#define REGISTERACTIVITIES_DATE_H
class Date{
private:
    int day, month, year;
public:
    Date(int giorno, int mese, int anno): day(giorno), month(mese), year(anno){}
    bool operator<(const Date &compare)const{ //copy in .cpp
        if(year<compare.year){
            return true;
        }else if(year==compare.year){
            if(month<compare.month){
                return true;
            }else if(month==compare.month){
                if(day<compare.day){
                    return true;
                }
            }
        }
        return false;
    }
    bool operator==(const Date &right)const{
        if(year == right.getYear() && month == right.getMonth() && day == right.getDay()){
            return true;
        }
        return false;
    }


    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};
#endif //REGISTERACTIVITIES_DATE_H
