#include "cfgproperty.h"

/* CfgProperty 클래스 생성자
 * cfg 파일을 불러오고 주요 설정값들을 멤버변수에 집어넣는다. */

CfgProperty::CfgProperty(QObject *parent) : QObject(parent)
{
    QFile file("yolov3.cfg");


    QStringList str_list;
    QStringList config;

    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            str_list.append(in.readLine());
        }
        file.close();
    }

//    if(file.open(QIODevice::WriteOnly))
//    {
//        QTextStream in(&file);
//        for(int i = 0;i<str_list.size();i++)
//        {
//            in<<str_list[i]<<endl;
//        }
//    }

    for(int i=0;i<18;i++)
    {
        //qDebug()<<str_list[(i+5)];
        config = str_list[i+5].split("=");
        qDebug()<<config;
        switch (i) {
        case 0:
            this->batch = config;
            break;
        case 1:
            this->subdivisions = config;
            break;
        case 2:
            this->width = config;
            break;
        case 3:
            this->height = config;
            break;
        case 4:
            this->channels = config;
            break;
        case 5:
            this->momentum = config;
            break;
        case 6:
            this->decay = config;
            break;
        case 7:
            this->angle = config;
            break;
        case 8:
            this->saturation = config;
            break;
        case 9:
            this->exposure = config;
            break;
        case 10:
            this->hue = config;
            break;
        case 12:
            this->learning_rate = config;
            break;
        case 13:
            this->burn_in = config;
            break;
        case 14:
            this->max_batches = config;
            break;
        case 15:
            this->policy = config;
            break;
        case 16:
            this->steps = config;
            break;
        case 17:
            this->scales = config;
            break;
        default:
            break;
        }
    }

    qDebug()<<this->decay;


    select_num = 0;

    //    while(!in.atEnd()){
    //        QString line = in.readLine();
    //        qDebug()<<line;
    //        qDebug()<<"sdf";
    //    }
}

/* CfgValue 를 가져오는 함수로
 * qml property가 두가지이상의 파라미터를 보낼 수 없다고 판단(190704 기준)되기에
 * 어떤 값을 가져올 것인지를 결정하는 select_num 의 값을 설정하는 property 와
 * 실제 필요한 값(cfgvalue)를 가져오는 property를 순서대로 호출 하는 방식을 사용
 *
 * getter 함수를 사용할때는 이러한 방식이 필요없지만 setter 함수와의 통일성을 위해 동일하게 작성
 * ex)qml상에서
 *  property.select_num = 0;
 *  value = property.getCfgValue;
 */
QString CfgProperty::getCfgValue()
{
    switch (select_num) {
    case 1:
        qDebug()<<this->batch[1];
        return  this->batch[1];
        break;
    case 2:
        return this->subdivisions[1];
        break;
    case 3:
        return this->width[1];
        break;
    case 4:
        return this->height[1];
        break;
    case 5:
        return this->channels[1];
        break;
    case 6:
        return this->momentum[1];
        break;
    case 7:
        return this->decay[1];
        break;
    case 8:
        return this->angle[1];
        break;
    case 9:
        return this->saturation[1];
        break;
    case 10:
        return this->exposure[1];
        break;
    case 11:
        return this->hue[1];
        break;
    case 12:
        return this->learning_rate[1];
        break;
    case 13:
        return this->burn_in[1];
        break;
    case 14:
        return this->max_batches[1];
        break;
    case 15:
        return this->policy[1];
        break;
    case 16:
        return this->steps[1];
        break;
    case 17:
        return this->scales[1];
        break;
    default:
        return "";
        break;
    }
}
/* cfgvalue 를 설정하는 함수로 넣고자 값을 파라미터로 가져온다.
 * 자세한 방식은 getCfgValue 함수 주석에 달아둠.
  */
void CfgProperty::setCfgValue(QString str)
{
    switch (select_num) {
    case 1:
        this->batch[1] = str;
        break;
    case 2:
        this->subdivisions[1] = str;
        break;
    case 3:
        this->width[1] = str;
        break;
    case 4:
        this->height[1] = str;
        break;
    case 5:
        this->channels[1] = str;
        break;
    case 6:
        this->momentum[1] = str;
        break;
    case 7:
         this->decay[1] = str;
        break;
    case 8:
         this->angle[1] = str;
        break;
    case 9:
         this->saturation[1] = str;
        break;
    case 10:
         this->exposure[1] = str;
        break;
    case 11:
         this->hue[1] = str;
        break;
    case 12:
         this->learning_rate[1] = str;
        break;
    case 13:
         this->burn_in[1] = str;;
        break;
    case 14:
         this->max_batches[1] = str;
        break;
    case 15:
         this->policy[1] = str;
        break;
    case 16:
         this->steps[1]= str;
        break;
    case 17:
         this->scales[1] = str;
        break;
    default:
        break;
    }
}

/* 가져올 설정값을 결정하는 select_num 변수를 가져오는 getter 함수*/
int CfgProperty::getSelectNum() const
{
    return this->select_num;
}

/* 가져올 설정값을 결정하는 select_num 변수를 설정하는 setter 함수 */
void CfgProperty::setSelectNum(int value)
{
    this->select_num = value;
}

/* cfg 파일을 저장하는 함수 */
void CfgProperty::SaveCfgFile()
{
    QFile file("yolov3.cfg");

    QStringList str_list;

    //원본 cfg 파일을 읽어오고 str_list 에 리스트 형태로 텍스트를 라인단위로 저장한다.
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            str_list.append(in.readLine());
        }
        file.close();
    }

    //WriteOnly로 열 경우 파일의 텍스트가 전부 날아가고 저장해뒀던 텍스트를 다시 덮어쓴다.
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream in(&file);
        int key;
        for(int i = 0;i<str_list.size();i++)
        {
            key = i;
            //주요 설정값이 있는 범위 5~22 는 저장해둔 혹은 변경된 값이 저장된 멤버변수 값을 새로 집어넣는다.

            if(i > 4 && i < 23)
            {

                switch (key) {
                case 5:
                    in<<this->batch[0]+"="+this->batch[1]<<endl;
                    break;
                case 6:
                    in<<this->subdivisions[0]+"="+this->subdivisions[1]<<endl;
                    break;
                case 7:
                    in<<this->width[0]+"="+this->width[1]<<endl;
                    break;
                case 8:
                    in<<this->height[0]+"="+this->height[1]<<endl;
                    break;
                case 9:
                    in<<this->channels[0]+"="+this->channels[1]<<endl;
                    break;
                case 10:
                    in<<this->momentum[0]+"="+this->momentum[1]<<endl;
                    break;
                case 11:
                    in<<this->decay[0]+"="+this->decay[1]<<endl;
                    break;
                case 12:
                    in<<this->angle[0]+"="+this->angle[1]<<endl;
                    break;
                case 13:
                    in<<this->saturation[0]+"="+this->saturation[1]<<endl;
                    break;
                case 14:
                    in<<this->exposure[0]+"="+this->exposure[1]<<endl;
                    break;
                case 15:
                    in<<this->hue[0]+"="+this->hue[1]<<endl;
                    break;
                case 16:
                    in<<""<<endl;
                    break;
                case 17:
                    in<<this->learning_rate[0]+"="+this->learning_rate[1]<<endl;
                    break;
                case 18:
                    in<<this->burn_in[0]+"="+this->burn_in[1]<<endl;
                    break;
                case 19:
                    in<<this->max_batches[0]+"="+this->max_batches[1]<<endl;
                    break;
                case 20:
                    in<<this->policy[0]+"="+this->policy[1]<<endl;
                    break;
                case 21:
                    in<<this->steps[0]+"="+this->steps[1]<<endl;
                    break;
                case 22:
                    in<<this->scales[0]+"="+this->scales[1]<<endl;
                    break;
                default:
                    break;
                }

            }
            else
            {
                in<<str_list[i]<<endl;
            }
        }

        qDebug()<<"저장성공!!";

    }

}


